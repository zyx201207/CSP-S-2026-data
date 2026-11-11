#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
bool cmp(int x,int y){
	return x<y;
}
map <int,int> s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
	}
	int p;
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			p=a[i]-a[j];
			if(a[i]==a[j]){
				break;
			}
			if(m==0&&j<i-1){
				cout<<i-1;
				return 0;
			}else if(m==0&&j==i-1){
				break;
			}
			if(a[j]<a[i]&&p<=m){
				m=m-a[i]+a[j];
				a[j]=a[i];
			}else if(p>m){
				break;
			}
			p=0;
		}
		if(m==0&&p<m){
			cout<<i;
			return 0;
		}else if(p>m){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
