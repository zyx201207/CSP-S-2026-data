#include<bits/stdc++.h>
using namespace std;
string a;
long long c[199999999];
string l;
long long sum,n,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	//youhua
	//10:50 shi zai xiang bu chu lai le si hu zhi neng yong dan ceng xun huan
	//yao bu ran kai 1e9 de shu zu hui bian yi shi bai
	//xi wang zhi shi fan wei ba bie TLE wo jiu xing
	for(int i=1;i<=n;i++){
		cin>>c[i];
		cin>>a;
		for(int j=1;j<=c[i];j++){
			l+=a;
		}
	}
	k=l.length();
	for(int i=0;i<(k/2);i++){
		if(l[i]==l[k-i-1])
			sum++;
	}
	cout<<k/2-sum;
	return 0;
	
	
	
	
	
}
