//GZ-J00271，秦卓屹，贵阳市第一中学
#include<bits/stdc++.h> 
using namespace std;
int n,m,num[200005],a1[200005][35],ans=0; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
		int p=0;
		while(num[i]>0){
			a1[i][34-p]=num[i]%2;
			num[i]/=2;
			p++;
		}
	}
	for(int i=0;i<35;i++){
		int sum=0; 
		for(int j=0;j<n;j++){
			sum+=a1[j][i];
			if(sum>=m){
				int t=1;
				for(int p=0;p<34-i;p++)
					t*=2;
				ans+=t;
			}
		}
	}
	cout<<ans;
	 
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
