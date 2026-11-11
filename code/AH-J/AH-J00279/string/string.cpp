#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,M=1e9;
int n,a[N];
ll l,d,cnt1,cnt2,minn=-1,sum;
char c[N];
string s,p1,q1,p2,q2;
bool fan(string s){
	string c=s;
	reverse(s.begin(),s.end());
	if(c==s){
		return 1;
	}
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum>M){
		cout<<sum/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	l=s.size();
	if(fan(s)){
		cout<<0;
		return 0;
	}
	//aababca   aaba abca   abaa abca
	if(l%2==1){
		d=l/2;
		for(int i=0;i<d+1;i++){
			p1+=s[i];
		}
		reverse(p1.begin(),p1.end());
		for(int i=d;i<l;i++){
			q1+=s[i];
		}
		for(int i=0;i<d+1;i++){
			if(p1[i]!=q1[i]){
				cnt1++;
			}
		}
//		cout<<p1<<" "<<q1<<endl;
		
		for(int i=0;i<d+1;i++){
			p2+=s[i];
		}
		reverse(p2.begin(),p2.end());
		for(int i=d;i<l;i++){
			q2+=s[i];
		}
		for(int i=0;i<d+1;i++){
			if(q2[i]!=p2[i]){
				cnt2++;
			}
		}
//		cout<<p2<<" "<<q2<<endl;
	}
	else{
		d=l/2;
		for(int i=0;i<d;i++){
			p1+=s[i];
		}
		reverse(p1.begin(),p1.end());
		for(int i=d;i<l;i++){
			q1+=s[i];
		}
		for(int i=0;i<d;i++){
			if(p1[i]!=q1[i]){
				cnt1++;
			}
		}
//		cout<<p1<<" "<<q1<<endl;
		
		for(int i=0;i<d;i++){
			p2+=s[i];
		}
		reverse(p2.begin(),p2.end());
		for(int i=d;i<l;i++){
			q2+=s[i];
		}
		for(int i=0;i<d;i++){
			if(q2[i]!=p2[i]){
				cnt2++;
			}
		}
//		cout<<p2<<" "<<q2<<endl;
	}
	
	minn=min(cnt1,cnt2);
	cout<<minn;
	return 0;
}
/*
S可以分成n个连续的段,其中第i(1≤i≤n)段由ai个小写英文字母ci构成

字符串S是回文串,当且仅当对于所有i(1≤i≤L),均有si=s(L+1)−i


aababaa

aababca


6
2 a
1 b
1 a
1 b
1 c
1 a
 
aabbaaaa
*/
*/
