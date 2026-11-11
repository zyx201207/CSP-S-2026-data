#include<bits/stdc++.h>
using namespace std;
long long a,n,num=0,sum=0;
char c;
string ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(int i=0;i<a;i++){
			ans+=c;
		}
		num+=a;
	}
	long long mid=num/2;
	for(long long i=mid;i<num;i++){
		if(ans[i]!=ans[num-1-i]){
			ans[i]=ans[num-1-i];
			sum++;
		}
		else continue;
	}
	cout<<sum;
}



