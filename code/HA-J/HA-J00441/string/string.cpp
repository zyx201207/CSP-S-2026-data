#include<bits/stdc++.h>
using namespace std;
string s[1000000];
int cou[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	cin>>n;
	long long x=0;
	for(int i=1;i<=n;i++){
		cin>>cou[i];
		cin>>s[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(i+t==n){
			cout<<x;
			break;
		}
			for(int j=t;j<n-i;j++){
				if(s[i]!=s[n-j]){
					if(cou[i]>cou[n-j]){
				 		cou[i]=cou[i]-cou[n-t];
				 		t++;
				 		x+=cou[n-t];
					}else{
				 		cou[n-t]==cou[n-t]-cou[i];
				 		x+=cou[i];
				 		break;
				 	}
				}else{
					if(cou[i]>cou[n-j]){
				 		cou[i]=cou[i]-cou[n-t];
				 		t++;
					}else{
				 		cou[n-t]==cou[n-t]-cou[i];
				 		break;
				 	}
				}
			}	
				
	}
	return 0;
}
