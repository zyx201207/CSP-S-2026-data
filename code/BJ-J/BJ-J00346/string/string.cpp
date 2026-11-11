#include<bits/stdc++.h>
using namespace std;
int a[200008];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;string s;
	s="";int sum=0;int cnt=0;int sumcnt=0;
	for(int i=1;i<=n;i++){
		int n;cin>>n;a[i]=n;
		char q;cin>>q;sum+=a[i];
		for(int i=1;i<=n;i++){
			s+=q;
		}
	}sumcnt=sum;
	while(true){
		if(s[sum-sumcnt]!=s[sumcnt-1]){
			cnt++;
		}if(sumcnt-1==(sum-1)/2){
			break;
		}
		sumcnt-=1;
		
	}if(sum/2-cnt<cnt){
		cnt=sum/2-cnt;
	}cout<<cnt;
}