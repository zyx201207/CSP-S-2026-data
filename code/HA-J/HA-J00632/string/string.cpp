#include<bits/stdc++.h>
using namespace std;
string word[1000005],sum1;
long long n,number[1000005],sum2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number[i]>>word[i];
		for(int j=1;j<=number[i];j++){
			sum1+=word[i];
		}
	}
	for(int i=1;i<=sum1.size()/2;i++){
		if(word[i]!=word[sum1.size()-i+1]){
			sum2++;
		}
	}
	cout<<sum2;
}
