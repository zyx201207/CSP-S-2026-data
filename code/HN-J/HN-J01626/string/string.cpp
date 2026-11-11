#include<bits/stdc++.h>
using namespace std;
long long a[100001],n,sam=0,sem=0,k=0;
char c[100001],S[200000000],S1[200000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			S[sam]=c[i];
			sam++;
		}
	}
	
	for(int j=sam-1;j>=sam/2;j--){
		S1[k]=S[j];
		k++;
	}
	sam=sam/2;
	for(int j=0;j<sam;j++){
		if(S1[j]!=S[j]){
			sem++;
		}
	}
	cout<<sem;
	return 0;
}
