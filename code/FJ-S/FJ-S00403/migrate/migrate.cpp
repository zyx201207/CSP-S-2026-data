#include <bits/stdc++.h>
using namespace std;
		int farisland[200001];
bool judge(int from,int destination){
	int aroad[200001];
	int temp=0;
	aroad[0]=1,aroad[1]=from;
	for (int i=from;i<=destination;i=farisland[i]){
	++aroad[0];
	aroad[aroad[0]]=i;
	}
	++aroad[0];
	aroad[aroad[0]]=destination;
	for (int i=1;i<aroad[0];++i){
		if (aroad[i+1]-aroad[i]>2||temp==1){return true;
		}
		else if (aroad[i+1]-aroad[i]==2) ++temp;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	int t;
	cin>>c>>t;
	for (int sbb=1;sbb<=t;++sbb){
		int n;
		long long d;
		cin>>n>>d;
		long long x[200001];
		for (int i=1;i<=n;++i){
			cin>>x[i];
		}
		for (int i=1;i<=n;++i){
			for (int j=n;j>=i;--j){
			if ((long long)x[j]-(long long)x[i]<=d) {farisland[i]=j;
			break;
			}
		}
		}
		int twopathisland=0;
		for (int i=1;i<=n;++i){
			for (int j=farisland[i]+1;j<=n;++j){
				
			if (j-2<=i||judge(i,j)) {continue;}else ++twopathisland;
		} 
		}
		cout<<twopathisland;
	}
	return 0;
} 

