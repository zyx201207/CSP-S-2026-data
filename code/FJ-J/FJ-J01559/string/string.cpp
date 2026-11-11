#include<bits/stdc++.h>
using namespace std;
//char arr[200005];
//long long shuu[200005];
//long long jsq;
char arr[200005];
long long shuu[200005];
long long jsq =0;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	char arr[200005];
//	long long shuu[200005];
//	long long jsq =0;
//	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%lld %c",&shuu[i],&arr[i]);
	}
	for(int i=1,j=n;i<j;){
		if(shuu[i]>=shuu[j]){
			if(arr[i]!=arr[j]){
				jsq+=shuu[j];
			}
			shuu[i]-=shuu[j];
			if(shuu[i]==0){
				i++;
			}
			j--;
		}
		else{
			if(arr[i]!=arr[j]){
				jsq+=shuu[i];
			}
			shuu[j]-=shuu[i];
			i++;
		}
	}
	cout<<jsq;
	return 0;
}
