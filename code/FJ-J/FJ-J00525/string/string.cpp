#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],k=0,ans=0;
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	char ca='#';
	for(int i=1;i<=n;i++){
		int ac;
		char c;
		cin>>ac>>c;
		if(c!=ca){
			k++;
			ch[k]=c;
		}
		a[k]+=ac;
		ca=c;//Ô¤´¦Àí 
	}
	/*
	for(int i=1;i<=k;i++){
		cout<<a[i]<<" "<<ch[i]<<endl;
	}
	cout<<k<<endl;
	*/
	int h=1;
	int t=k;
	while(h<t){
		long long mi;
		if(a[h]==a[t]){
			mi=a[h];
		}else{
			mi=min(a[h],a[t]);
		}
		
		//cout<<"mi:"<<mi<<endl;
			a[h]-=mi;
			a[t]-=mi;
			if(ch[h]!=ch[t]){
				ans+=mi;
			}
			if(a[h]==0){
				h++;
			}
			if(a[t]==0){
				t--;
			}
	}
	cout<<ans;
	return 0;
}
