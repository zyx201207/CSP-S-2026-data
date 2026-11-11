#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main(){
	int n;
	int time;
	int su=0;
    char w;	
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);	
    cin>>n;
    for(int i=0;i<n;i++){
        int sum;	
    	cin>>sum;
    	cin>>w;
    	for(int i=su;i<=sum+su;++i){
    		s[i]=w;
		}
    	su+=sum;		
	}
	int l=0,r=su-1;
//    for(int i=1;i<=su;i++){
//
//		l=1+1;
//		r=r-1;
//		if(l>r){
//			if(time!=0)
//		+1;
//			else
//			    cout<<0;
//			return 0;
//		}
//	}
	while(l<=r){
    	if(s[l]!=s[r]){
    		time++;
		}	
		l++;
		r--;	
	}
	cout<<time;
	return 0;
} 
