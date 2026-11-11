#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string sum;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=n;i++){
        int m;
        string s;
        cin>>m;
        cin>>s;
        
        for(int j=1;j<=m;j++){

            sum=sum+s;
        }
        
    }

    long long s=sum.size();
    int cnt=0;
    for(int i=1;i<=s;i++){
    	if(sum[i]!=sum[s]){
    		cnt++;
    		s--;
		}	
	} 
	for(int i=1;i<=n;i++){
        if(sum[i]==sum[n]){
        	cout<<0;
        	return 0;
		}
        
    }
    cout<<cnt;
    return 0;
}
