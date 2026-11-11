#include<bits/stdc++.h>
using namespace std;
long long a[200010],aa[200010];
string b[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	long long cnt=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		aa[i]=a[i];
		ans+=a[i];
	}
	cout<<ans<<endl;
	if(ans<=10000000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++)s=s+b[i];
		}
		for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
			if(s[i]!=s[j])cnt++;
		}
		cout<<1<<endl;
	}
	else{
		for(int i=1,j=n;i<=n/2;i++,j--){
			int x=0;
			if(a[i]==a[j]&&b[i]!=b[j]){
				cnt+=a[j];
				b[j]=b[i];
				x=1;
			}
			else if(a[i]==a[j]&&b[i]==b[j]){
				cnt+=0;x=2; 
			}
			else if(a[i]<a[j]&&b[i]==b[j]){
				a[j]-=a[i];
				j++;
				x=3;
			}
			else if(a[i]>a[j]&&b[i]==b[j]){
				a[i]-=a[j];
				i--;
				x=4;
			}
			else {
				if(a[i]>a[j]&&b[i]!=b[j]){
					cnt+=a[j];
					a[i]-=a[j];
					i--;
					x=5;
				}
				else{
					cnt+=a[i];
					a[j]-=a[i];
					j++;
					x=6;
				}
			}
		}
		cout<<2<<endl;
	}
	cout<<ans<<' '<<cnt<<endl;
	return 0;
}
//aabccbdhj
//7
//2 a
//1 b
//2 c
//1 b
//1 d
//1 h
//1 j
//aabcccbaa
//aabcccbaa 
//aabccbdhj
