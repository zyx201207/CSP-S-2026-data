#include<bits/stdc++.h>
using namespace std;
struct un{
	int y;
	char p;
}a[200005];
char g[30]={'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','z','y','z'};
long long n,o,b[30],r,l=1,t;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].y>>a[i].p;
		o+=a[i].y;
		for(int j=1;j<=26;j++){
			if(a[i].p==g[j]){
				b[j]+=a[i].y;
				break;
			}
		}
	}
	sort(b+1,b+27,cmp);
	r=o;
	if(b[1]==b[2] && b[3]==0){
		cout<<b[1];
		return 0;
	}
	if(b[2]==0){
		cout<<0;
		return 0;
	}
	for(int i=1,j=n;l<r;l++,r--){
		if(l>a[i].y){
			i++;
		}
		if(r<a[j].y){
			j--;
		}
		if(a[i].p!=a[j].p){
			t++;
		}
	}
	cout<<t;
	return 0;
}

