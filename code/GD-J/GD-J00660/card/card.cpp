#include <bits/stdc++.h>
using namespace std;
int kp[100005];
int s[100005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,shu;
	cin>>n>>shu;
	for(int i=1;i<=n;i++){
		cin>>kp[i];
		bool cf=false;
		int x;
		for(int j=1;j<=i;j++){
			if(kp[i]==kp[j]){ 
				x=j;
				cf=true;
				for(int d=j;d<i;d++){
					kp[d]=0;
				}
			}
		}
		for(int z=1;z<=i;z++){
			s[kp[z]]++;
			cout<<kp[z];
		}
		cout<<endl;
	}
	for(int i=1;i<=shu;i++){
		cout<<s[i]<<" ";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
