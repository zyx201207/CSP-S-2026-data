#include<bits/stdc++.h>
using namespace std;
long long num,n[200005],cnt,start=0,end1;
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>n[i]>>s[i];
	}
	end1=num-1;
	while(1){
		if(start==end1){
			cout<<cnt;
			return 0;
		}
		if(s[start]==s[end1]){
			if(n[start]>n[end1]){
				n[start]-=n[end1];
				n[end1]=0;
				end1--;
			}
			else{
				n[end1]-=n[start];
				n[start]=0;
				start++;
			}
		}
		else{
			if(n[start]>n[end1]){
				n[start]-=n[end1];
				cnt+=n[end1];
				n[end1]=0;
				end1--;
			}
			else{
				n[end1]-=n[start];
				cnt+=n[start];
				n[start]=0;
				start++;
			}
		}
	}
	return 0;
} 
