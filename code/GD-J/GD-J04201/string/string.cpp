#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
};
long long ans=0;
node a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].c==a[j].c){
			int mi=min(a[i].a,a[j].a);
			a[i].a-=mi;
			a[j].a-=mi;
		}else{
			ans+=min(a[i].a,a[j].a);
			if(a[i].a<=a[j].a){
				a[j].a-=a[i].a;
				a[i].a=0;
			}
			else{
				a[i].a-=a[j].a;
				a[j].a=0;
			}
		}
		if(!a[i].a) i++;
		if(!a[j].a) j--;
	}
	cout<<ans;
	return 0;
}

