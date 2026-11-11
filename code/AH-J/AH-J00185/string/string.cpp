#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long n,a[500010],cnt,sum[500010],sl=0,ms=1;
char ch[500010],sr[500010];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>sr[i];
		if(a[i]*n>=1e8)ms=2;
		if(sr[i]==sr[i-1])sum[sl]+=a[i];
		else{
			sl++;
			sum[sl]+=a[i];
			ch[sl]=sr[i];
		}
	}
	if(ms==2){
		int r=1,l=sl;
		while(r<=l){
			if(ch[r]==ch[l]){
				if(sum[r]>sum[l]){
					sum[r]-=sum[l--];
				}
				else if(sum[l]>sum[r]){
					r++;
					sum[l]-=sum[r++];
				}
				else l--,r++;
			}
			else{
				if(sum[r]>sum[l]){
					cnt+=sum[l];
					sum[r]-=sum[l--];
				}
				else if(sum[l]>sum[r]){
					cnt+=sum[r];
					sum[l]-=sum[r++];
				}
				else{
					cnt+=sum[l];
					l--,r++;
				}
			}
		}
		cout<<cnt;
	}
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++)
				s+=sr[i];
		string S=s;
		reverse(S.begin(),S.end());
		long long len=s.size();
		for(int i=0;i<len/2;i++){
			if(s[i]!=S[i]){
				cnt++;
				//cout<s[i]<<" "<<S[i]<<endl;
			}
		}
		cout<<cnt;	
	}
	return 0;
}
