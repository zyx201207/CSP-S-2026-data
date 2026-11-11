#include<bits/stdc++.h>
using namespace std;
//ans
//int jiama(string a){int cnt=0;
//	for(int i=a.size()-1;i>=0;i--){
//		cnt*=27;
//		cnt+=(a[i]-'a'+1);
//	}return cnt;
//} 
//string jiema(int a){string cnt="";
//	while(0<a){
//		cnt=(string(a%27))+cnt;
//	}return cnt;
//}
//struct stru{
//	int l,r,z,s;
//}vector<int> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string ask;
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		string q;
		cin>>c>>q;
		for(int i=1;i<=c;i++)ask+=(q);
	}
	int siz=ask.size();
	int c=0;
	for(int i=0;i<=(siz/2);i++){
		if(ask[siz-i-1]!=ask[i])c++;
//		cout<<siz-i-1<<":"<<ask[siz-1-i]<<"   "<<i<<":"<<ask[i]<<endl;
	}cout<<c;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
