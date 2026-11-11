#include <bits/stdc++.h>
using namespace std;
int o,t;
long long nums[100010];
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>o>>t;
	for(int i=1;i<=t;i++){
		long long n1,d,num1=0,n;
		cin>>n1>>d;
		int y=0;
		for(int j=1;j<=n1;j++){
			cin>>nums[j];
			if(j>1 && nums[j]-nums[j-1]>d && y==0) {
				n=j-1;
				y++;
			}
		}
		for(int j=1;j<=n;j++){
			if(nums[n]-nums[j]<=d) break;
			
			int step1=0,step2=0;
			for(int k=j+1;k<=n;k++){
				
				if(nums[k]-nums[j]<=d && (nums[k+1]-nums[j])>d){
					step1=k;
					break;
				}
				
			}
			for(int k=step1+1;k<=n;k++){
				if(nums[k]-nums[step1]<d &&(nums[k+1]-nums[step1]>=d)){
					step2=k;
					if(step2-step1>=1 && step1-j==1) num1++;
					break;
				}else if(nums[k]-nums[step1]<d &&(nums[k+1]-nums[step1]>=d || k==n)){
					step2=k;
					break;
				}
			}
			
			
			int tq=0;
			if(step2==0) tq+=9;
			for(int g=1;g<=step1-j-1;g++){
				if(tq>1) break; 
				if(d*2+nums[j]-nums[step2]>=nums[step1]-nums[step1-g]){
					tq++;
				}
			}
			if(tq==1) num1++;
			
			
			
		}
		cout<<num1<<endl;
		for(int j=1;j<=n;j++){
			nums[j]=0;
		}
	}
	return 0;
}		
