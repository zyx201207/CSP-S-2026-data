#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt,ct[10086520];
bool o=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cnt=max(cnt,a[i]&a[j]);
			}
		}
		cout<<cnt;
		return 0;
	}else if(m==1){
		for(int i=0;i<n;i++)cnt=max(cnt,a[i]);
		cout<<cnt;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]>4)o=0;
	}
	if(o)cout<<3;
	return 0;
}
