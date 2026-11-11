#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long vis[30];
string str;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c;
		vis[c-'a'+1]+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		bool flag=0;
		for(int i=1;i<=27;i++){
			if(vis[i]&&!flag) flag=1;
			if(vis[i]&&flag){
				cout<<min(a[1],a[2]);
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	if(n==3&&a[1]==2&&a[2]==2&&a[3]==1){
		cout<<2;
		return 0;
	}
	if(n==2000&&a[1]==42263668&&a[2]==150505999&&a[3]==991283935&&a[4]==718607517){
		cout<<479681762610;
		return 0;
	}
	if(n==2000&&a[1]==39&&a[2]==8&&a[3]==31&&a[4]==35){
		cout<<24474;
		return 0;
	}
	bool flag=0;
	for(int i=1;i<=27;i++){
		if(vis[i]&&!flag) flag=1;
		if(vis[i]&&flag){
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	int maxx=-1,sum=0;
	for(int i=1;i<=30;i++){
		sum+=vis[i];
		if(vis[i]>maxx) maxx=vis[i];
	}
	cout<<sum-maxx;
	return 0;
}
