#include<bits/stdc++.h>
using namespace std;
int N,M,appear[300005],v[300005],x[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>x[i];
		v[x[i]]++;
	}
	for(int i=1;i<=M;i++){
		if(v[i]>1){
			if(x[N-1]==i)appear[i]=N;
			else appear[i]=N-1;
		}
	}
	for(int i=1;i<=M;i++)cout<<appear[i]<<" ";
	return 0;
}
