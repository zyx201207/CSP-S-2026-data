#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[240];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,ddd=0,hhh=0;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		hhh+=a;
		if(v[(int)c]==0){
			ddd++;
			v[(int)c]+=a;
		}
	}
	int min=67676767,min2=67676767;
	if(ddd==1) cout<<0;
	else if(ddd==2){
		for(int i='a';i<='z';i++){
			if(v[i]!=0&&min>v[i])min=v[i];
		}
		cout<<min;
	}else if(ddd==3){
		for(int i='a';i<='z';i++){
			if(v[i]!=0&&min>v[i]){
				min2=min;
				min=v[i];
			}
		}
		cout<<min+min2;
	}else{
		cout<<hhh-1;
	}
    return 0;
}
