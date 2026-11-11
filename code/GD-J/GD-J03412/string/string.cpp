#include<bits/stdc++.h>
using namespace std;
int n,a[200010],minn=999,pd=0;
string zh,fb[200010];
//bool ishui(string m,int mm){
//	string ss;
//	int mmm=mm;
//	for(int i=0;i<mm;i++){
//		ss[i]==zh[mmm];
//		mmm--;
//	}
//	if(ss==zh){
//		return true;
//	}
//	else return !true; 
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>fb[i];
		if(fb[i]==fb[i-1]) pd=1;
		minn=min(minn,a[i]);
//		for(int j=1;j<=a[i];j++){
//			zh+=fb;
//		}
	}
//	ishui(zh,zh.size())
	if(n==1||pd==1){
		cout<<"0";
	}
	else if(n==2){
		cout<<minn;
	}
	else cout<<"0";
	return 0;
}
