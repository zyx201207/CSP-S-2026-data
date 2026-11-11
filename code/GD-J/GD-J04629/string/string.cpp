#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int a[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0,ma=0;
	cin >>n;
	for(int i=0;i<n;i++){
		cin >>a[i] >>s[i];
		ma+=a[i];
	}
	int tmp=0;
	char tm='1';
//	if(ma<=1e5+10){
		string str;
		int k=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<a[i];j++){
				str.push_back(s[i]);
				k++;
			}
		}
		for(int i=0,j=k;i<j;i++,j--){
			if(str[i]!=str[j]){
				ans++;
			}
		}
//	}
//	else{
//		for(int i=0,j=n-1;i<j;i++,j--){
//			if(s[i]==s[j]){
//				if(a[i]>a[j]){
//					if(tm!='1'){
//						if(s[i]==tm){
//							if(tmp>a[i]){
//								tmp-=a[i];
//								ans+=tmp;
//								tm='1';
//								tmp=0;
//							}else{
//								a[i]-=tmp;
//								tm='1';
//							}
//						}else{
//							if(tmp>a[i]){
//								tmp-=a[i];
//								ans+=tmp;
//								tm='1';
//								tmp=0;
//							}else{
//								
//							}
//						}
//					}
//					tmp+=a[j]-a[i];
//					tm=s[j];
//				}else if(a[i]<a[j]){
//					tmp+=a[i]-a[j];
//					tm=s[i];
//					if(tm!='1'){
//						if(s[j]){
//						}
//					}
//				}
//			}else{
//				
//			}
//		}
//	}
	cout <<ans;
	return 0;
}
