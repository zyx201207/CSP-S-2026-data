#include<bits/stdc++.h>
using namespace std;
//struct Node{
//	long long len;
//	long long st;
//	long long ed;
//	char c;
//}arr[200009];
long long n,all,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int kk=1;kk<=n;kk++){
		long long len;
		char c;
		cin>>len>>c;
		all+=len;
		for(long long i=1;i<=len;i++){
			s+=c;
		}
	}
	long long p=1,q=all;
	for(long long i=0;i<=all/2+1;i++){
		if(p==q){
			break;
		}else if(s[q]!=s[p]){
			cnt++;
		}
		p++,q--;
	}
	cout<<cnt;
//	cin>>n;
//	for(int mnmn=1;mnmn<=n;mnmn++){
//		cin>>arr[mnmn].len>>arr[mnmn].c;
//		arr[mnmn].st=all+1;
//		arr[mnmn].ed=all+arr[mnmn].len;
//		all+=arr[mnmn].len;
//	}
//	long long p=1,q=all,pi=1,qi=n;
//	for(int i=1;i<=n;i++){
//		if(arr[pi].c!=arr[qi].c){
//			bool f=1,g=1;
//			long long Min=min(arr[pi].len,arr[qi].len);
//			cnt+=Min;
//			p=p+Min;
//			q=q-Min;
//			if(q>=arr[qi].st && q<=arr[qi].ed){
//				arr[qi].ed=q;
//				arr[qi].len=arr[qi].ed+1-arr[qi].st;
//				f=0;
//			}else if(p>=arr[pi].st && p<=arr[pi].ed){
//				arr[pi].st=p;
//				arr[pi].len=arr[pi].ed+1-arr[pi].st;
//				g=0;
//			}
//			cout<<' '<<cnt<<endl;
//			if(f==1){
//				qi++;
//				//cout<<'f';//
//			}else if(g==1){
//				pi++;
//				//cout<<'g';//
//			}
//			//cout<<'K';//
//		}
//		if(q<0 || p>all || qi<0 || pi>n) break;
//	}
	return 0;
}
