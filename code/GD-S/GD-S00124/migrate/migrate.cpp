#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long xi[20000060];
long long min_road_xi[20000060];

long long ans(int s){
	for(long long i=s;i<n;i++){
			
		if(i==s) min_road_xi[i]=0;
		
		else if( abs(xi[i]-xi[s])<=d ){
			min_road_xi[i]=1;
		}
			
		else{
				
			long long min_road;
			long long min_road_sum=0;
			min_road=100000000000180;
			for(long long j=i-1;abs(xi[i]-xi[j])<=d;j--){
				if(min_road_xi[j]<min_road){
					min_road=min_road_xi[j];
					min_road_sum=1;
				}
				else if(min_road_xi[j]==min_road){
					min_road_sum+=1;
				}
			}
			min_road_xi[i]=min_road_sum;
		}
			
	}
	long long sum_min_road=0;
	for(long long i=s;i<n;i++){
		if(min_road_xi[i]==2) sum_min_road+=1;
	}
	return sum_min_road;
}

int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long T=0;T<t;T++){
		cin>>n>>d;
		for(long long i=0;i<n;i++) cin>>xi[i];
		
		int sum=0;
		for(long long i=0;xi[i]+d<n;i++){
			sum+=ans(i);
		}
		cout<<sum<<endl;
		
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
