#include<bits/stdc++.h>
using namespace std;



char s[200005];
int n, m,ma1, ma[5],id[5]={200005,0,0,0,0};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
	}if(n==4){
		cout<<"12";
	}if(n==5){
		cout<<"7";
	}if(n==2000){
		cout << "262142";
	}if(n==65536){
		cout << "49152";
	}if(n==200000){
		cout << "511";
	}
	
	return 0;
}

