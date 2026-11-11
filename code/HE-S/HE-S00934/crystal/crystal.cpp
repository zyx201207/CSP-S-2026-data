#include<bits/stdc++.h>
using namespace std;
int c,n;
long long m;
struct node{
	int a1,a2;

}a[500005];
bool cmp(node x,node y){
	return x.a1<y.a1;
}
bool cnp(node x,node y){
	return x.a2<y.a2;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1;
	} 
	sort(a+1,a+1+n,cmp);
	if(n%2==0){
		for(int i=1;i<=n;i++){
			if(a[i].a1>=a[n/2].a1){
				a[i].a2=a[i].a1-a[n/2].a1;
			}else{
				a[i].a2=a[n/2].a1-a[i].a1;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i].a1>=a[n/2+1].a1){
				a[i].a2=a[i].a1-a[n/2+1].a1;
			}else{
				a[i].a2=a[n/2+1].a1-a[i].a1;
			}
		}
	}
	sort(a+1,a+1+n,cnp);
	for(int i=1;i<=n;i++){
		if(m<=0){
			break;
		}
		m-=a[i].a2;
		c++;
	}
	cout<<c;
	return 0;
} 
