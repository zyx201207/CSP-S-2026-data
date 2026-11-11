#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	
//	freopen("string3.in","r",stdin);
//	freopen("string3.out","w",stdout);

	int n;
	string s;
	cin>>n;
	while(n--){
		int ai;char ci;
		cin>>ai>>ci;
		while(ai--){
			s+=ci;
		}
	}
	int len=s.size();
	string s1,s2;
	if(len%2==1){
		for(int i=0;i<len/2;i++) s1+=s[i];
		for(int j=len-1;j>len/2;j--) s2+=s[j];
	}
	else {
		for(int i=0;i<len/2;i++) s1+=s[i];
		for(int j=len-1;j>=len/2;j--) s2+=s[j];
	}
	
	int ans=0; 
	for(int i=0;i<len/2;i++){
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}



//#include <bits/stdc++.h>
//using namespace std;
//
//int pos[200005],prep[200005];
//char c[200005];
//int main(){
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
////	
////	freopen("string3.in","r",stdin);
////	freopen("string3.out","w",stdout);
//
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>pos[i]>>c[i];
//		prep[i]=prep[i-1]+a[i];
//	}
//	int l=1,r=n,start=1,end;
//	while(1){
//		int nextl=pos[l+1],nextr=pos[r-1],nextr_=prep[n]-nextr;
//		if(nextl<nextr_){
//			end=nextl;
//			l=nextl;
//		}
//		else if(nextl>nextr_){
//			end=nextr_;
//			r=nextr;
//		}
//		else{
//			end=nextr_;
//			l=nextl;
//			r=nextr;
//		}
//		if()
//	}
//	
//	
//	return 0;
//}
