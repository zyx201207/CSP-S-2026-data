#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,m,a[500005];
int idx,maxi;
struct numbers{
    long long num;
	int time;
};
vector<numbers> arr(500005);

bool dc;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
    sort(a,a+n);
    long long gcha=a[1]-a[0];
    if(a[n-1]-a[n-2]!=gcha) dc=1;
    for(int i=2;i<n&&!dc;i++){
        if(a[i]-a[i-1]!=gcha){dc=1;break;}
    }
    //cout<<"I comp\n";
    //judge deng cha shu lie
	if(!dc){
        if(!gcha) return cout<<n,0;
        for(long long i=1;i<n;i++){
            if(m/gcha<i*(i+1)/2) return cout<<i,0;
            if(i==n-1) return cout<<n,0;
        }
    }
	
	if(m>10000000000) return cout<<n,0;
	
	for(int i=0;i<n;i++){
        if(!i){
            arr[0].num=a[0],++arr[0].time;
        }else if(a[i]!=a[i-1]){
            maxi=(arr[maxi].time<arr[idx].time?idx:maxi);
            arr[++idx].num=a[i],++arr[idx].time;
        }else{
            ++arr[idx].time;
        }
    }++idx;
    //cout<<"II comp\n";
    /*
    //ceshi1
	for(int i=0;i<idx;i++){
        cout<<arr[i].num<<' '<<arr[i].time<<'\n';
    }cout<<maxi;
    //ceshi1/
    */
    int ans=arr[maxi].time;
    while(1){
    	//cout<<m<<'\n';//ceshi2
    	if(idx==1) return cout<<n,0;
    	if(!maxi){
    		if((arr[1].num-arr[0].num)*(long long)arr[0].time<=m){
    			ans+=arr[1].time,m-=(arr[1].num-arr[0].num)*(long long)arr[0].time,--idx;
    			arr[1].time+=arr[0].time;
    			arr.erase(arr.begin());
			}else break;
		}else if(maxi==idx-1){
			if((arr[idx-1].num-arr[idx-2].num)*(long long)arr[idx-2].time<=m){
    			ans+=arr[idx-2].time,m-=(arr[idx-1].num-arr[idx-2].num)*(long long)arr[idx-2].time;
    			arr[idx-1].time+=arr[idx-2].time;
    			arr.erase(arr.begin()+maxi);
    			--idx,--maxi;
			}else break;
		}else{
			if(arr[maxi].num-arr[maxi-1].num<=arr[maxi+1].num-arr[maxi].num){//up->shang == down->up
				if(m>=(arr[maxi].num-arr[maxi-1].num)*(long long)arr[maxi-1].time){
					m-=(arr[maxi].num-arr[maxi-1].num)*(long long)arr[maxi-1].time,ans+=arr[maxi-1].time;
					if(!m) return cout<<ans,0;
					arr[maxi].time+=arr[maxi-1].time;
					arr.erase(arr.begin()+maxi-1);
					--idx,--maxi;
				}else{
					ans+=m/(arr[maxi].num-arr[maxi-1].num);
					break;
				}
			}else{
				if(m>=(arr[maxi].num-arr[maxi-1].num)*arr[maxi-1].time){
					m-=(arr[maxi].num-arr[maxi-1].num)*arr[maxi-1].time,ans+=arr[maxi-1].time;
					if(!m) return cout<<ans,0;
					arr[maxi].time+=arr[maxi-1].time;
					arr.erase(arr.begin()+maxi-1);
					--idx,--maxi;
				}else if(m>=(arr[maxi+1].num-arr[maxi].num)*arr[maxi].time){
					m-=(arr[maxi+1].num-arr[maxi].num)*arr[maxi].time,ans+=arr[maxi+1].time;
					if(!m) return cout<<ans,0;
					arr[maxi+1].time+=arr[maxi].time;
					arr.erase(arr.begin()+maxi);
					--idx;
				}else{
					ans+=m/(arr[maxi].num-arr[maxi-1].num);
					break;
				}
			}
		}
	}cout<<ans;
    

	return 0;
}
//zhong shu?
//Which of them appeared most?
//How many are they?
//I wonder how will it work if it inputs (5 4 \n 3 3 3 3 4) because the energy of it can only increase.
//kore DP desuka? wo bu tai hui DP. DP zettai muri da.      tanxin?
//11 2    2 2 3 5 8 8 6 8 9 1 4 5
//si lu hao xiang you le. dan shi dai ma hen fu za.

