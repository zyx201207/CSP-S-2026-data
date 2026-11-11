#include<bits/stdc++.h>
using namespace std;
const int maxc=5e5+100;
int powerf[maxc]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>powerf[i];
	sort(powerf,powerf+n);
	int num=1;
	for(int i=n-2;i>=0;i--){
		m=m-(powerf[n-1]-powerf[i]);
		if(m<0){
			break;
		}
		num+=1;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
