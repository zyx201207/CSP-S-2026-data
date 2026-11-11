#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+5;
//int a1[]
int n;
ll len1=0,len2=0;
ll a[MAXN],b[MAXN],d[MAXN];
char c[MAXN],s1[MAXN],s2[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	string s1,s2;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];++j){
			s1+=c[i];
		}
	}
	ll mid=s1.size()/2;
	ll len=s1.size();
	ll cnt=0;
	for(int i=0;i<mid;++i){
		if(s1[i]!=s1[len-i+1]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	//int j=0;
	//for(int i=s1.size()-1;i>=0;--i){
		//cout<<s1[i];
	//}
	//cout<<s1<<endl<<s2;
	
	/*ll mid=(len>>1);
	for(int i=1,fl=0;i<=n;++i){
		if(len2+a[i]>=mid){
			if(mid%2==0){
				b[i]=mid-(len2+1)+1;
				s1[i]=c[i];
				//d[]
			}
			else{
				b[i]=mid-1-(len+1)-1;
				s1[i]=c[i];
			}
			fl=1;
		}
	}
*/
	return 0;
}
