#include<iostream>
using namespace std;
int n;
int ans=0;
int s[200010][2];
int getchr(int pos){
	int x;
	int i;
	while(x<=pos){
		x+=s[i][0];
		i++;
	}
	return s[i-1][1];
}
long long size=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		char x;
		long long e;
		cin>>e>>x;
		size+=e;
		s[i][0]=i==0?e:e+s[i-1][0];
		s[i][1]=int(x);
	}
	//cout<<size<<endl;

	for(int i=0;i<size/2;i++){
		long long endp=size-1-i;
		if(getchr(i)!=getchr(endp)){
			ans++;
	//		cout<<i<<endp<<endl;
		} 
	}
	
	cout<<ans;
}
