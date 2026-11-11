#include<bits/stdc++.h>
using namespace std;
int a[200100][31],v[200100],arr[31];
void p(int x,int num){
	string s;
	while(x>0){
		if(x%2==1) s=s+'1';
		else s=s+'0';
		x/=2;
	}
	for(int i=s.size()-1;i>=0;i--) a[num][i]=int(s[i]-'0');
}
int main(){
	ifstream ifs("and.in");
	ofstream ofs("and.out");
	
	arr[0]=1;
	for(int i=1;i<31;i++) arr[i]=arr[i-1]*2;
	
	int n,m;
	ifs>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		ifs>>x;
		p(x,i);
	}
	
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=0;j<n;j++) if(a[j][i]==1 && v[j]==0) cnt++;	
		if(cnt>=m){
			ans+=arr[i];
			for(int j=0;j<n;j++) if(a[j][i]==0) v[j]=1;
		}
	}
	ofs<<ans;
	return 0;
}
