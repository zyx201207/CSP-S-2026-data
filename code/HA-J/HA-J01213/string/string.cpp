#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	char a[200005];
	unsigned long long num[200005],n,K=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i]>>a[i];
		for(int j=0;j<num[i];j++){
			S+=a[i];
			K++;
		}
	}
	int sum=0;
	for(int i=0,j=K-1;i<K,j>=0;i++,j--){
		if(S[i]!=S[j]) sum++;
	}
    cout<<sum/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
