#include<bits/stdc++.h>
using namespace std;
const long long N=5000000;
long long c,t,n,d,a,x[N],ne[N],ans;
short ha[N][N][N];
int main(){
	cin>>c>>t;
	while(t){
		cin>>n>>d;
		int j=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1&&x[i]-x[j]<=d) ne[j] = i;
			else j++;
			
		} 
		cout<<1<<endl;
		t--;
	}
	return 0;
}
