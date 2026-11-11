#include<bits/stdc++.h>
using namespace std;
long long num[200005],n,all,bigg,ans,ans2;
string w[200005],wo;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>num[i]>>w[i];
    	if(num[i]>100000000)bigg++;
    	all =all+num[i];
       
	}
	string aa =w[0];
	for(int i=0;i<n;i++){
		if(aa==w[i])ans++;
	}
	
	if(ans==n){
		cout<<"0";
		return 0;
	}
		for(int i=0;i<n;i++){
		for(int j=0;j<num[i];j++){
		wo +=w[i];
	}
	}
	  for(int i=0;i<all/2;i++){
	  	if(wo[i]!=wo[all-1-i])ans2++;
	  }
	cout<<ans2;
	
	return 0;
} 
