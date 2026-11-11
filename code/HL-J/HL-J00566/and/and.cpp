#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==n){
    	int ans=0;
    	cin>>ans;
    	for(int i=1;i<n;i++){
    		int a;
    		cin>>a;
    		ans = ans&a;
		}
		cout<<ans;
		return 0;
	}
	vector<int> nums(n);
	for(int i=0;i<n;i++){
    	cin>>nums[i];
	}
	if(m==1){
		sort(nums.begin(),nums.end(),[](const int a,const int b){
			return a>b;
		});
		cout<<nums[0];
		return 0;
	}
	if(m==2){
		int best=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(nums[i]&nums[j]>best){
					best=nums[i]&nums[j];
				}
			}
		}
		cout<<best;
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(nums[i]&nums[j]&nums[k]>best){
						best=nums[i]&nums[j]&nums[k];
					}	
				}
				
			}
		}
	}else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						if(nums[i]&nums[j]&nums[k]&nums[l]>best){
							best=nums[i]&nums[j]&nums[k]&nums[l];
						}	
					}
						
				}
				
			}
		}
	}

	
	return 0;
}



