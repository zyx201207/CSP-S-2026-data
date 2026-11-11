#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	long long i=0,j=n-1;
	vector<long long> shuliang(n+2);
	vector<char> zimu(n+2);
	for(int i=0;i<n;i++){
		cin>>shuliang[i]>>zimu[i];
	}
	for(int i_=0;i_<n;i_++){
		int temp;
		if(shuliang[i]<shuliang[j]) temp = i;
		else temp = j;
		sum+=shuliang[temp]*(zimu[i]!=zimu[j]);
		if(temp==i){
			i++;
		}
		else{
			shuliang[i]-=shuliang[temp];
		}
		if(temp==j){
			j--;
		}
		else{
			shuliang[j]-=shuliang[temp];
		}
		if(j-i<1)break;
	}

	cout<<sum;
	return 0;
} 
