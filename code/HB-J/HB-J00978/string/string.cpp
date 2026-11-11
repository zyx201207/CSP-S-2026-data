#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long a[1000005]={};
    string s;
    string s1;
    cin>>n;
    for(long long i=1;i<=n;i++){
		
		cin>>a[i]>>s;
		for(long long j=1;j<=a[i];j++){
			s1+=s;
		}
	}
	long long sum=0;
   	long long i=0,j=s1.size()-1;
		while(i<j){
			if(s1[i]!=s1[j]){
				sum++;
			}
			i++;
			j--;
		}
	cout<<sum;

	return 0;
}
