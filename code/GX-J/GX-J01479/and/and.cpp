#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<long long>num(n);
    for(int i=0;i<n;i++){
		cin>>num[i];
	}
	if(m==2){
	long long max_ans=0;
	for(long long i=0;i<=n-m;i++){
	    	for(long long j=i+1;j<n;j++){
		        max_ans=fmax(max_ans,num[i]&num[j]);		
		}
	}
	cout<<max_ans;}
	else if(m==1){
	    long long max_ans=0;
	    for(long long i=0;i<n;i++){
			max_ans=max(max_ans,num[i]);
		}
		cout<<max_ans;	
	}
	else if(m==n){
	    long long max_ans=num[0];
	    for(long long i=1;i<n;i++){
			max_ans=(max_ans&num[i]);
		}	
		cout<<max_ans;
	}
    return 0;
}
