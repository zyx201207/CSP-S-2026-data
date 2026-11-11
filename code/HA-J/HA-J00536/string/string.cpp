#include<bits/stdc++.h>
using namespace std;
string s,s1;
char a1;
long long n,m,l=0,a[200006],k=0;
map<char,long long>ma;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    bool f=0;
    cin>>a[1]>>a1;
    l+=a[1]%2;
    char a2=a1;
    m+=a[1];
    ma[a1]=a[1];
    k=max(k,ma[a1]);
    for(int i=2;i<=n;i++){
    	cin>>a[i]>>a1;
        l+=a[i]%2;
       
        	ma[a1]+=a[i];
        	k=max(k,ma[a1]);
	
        m+=a[i];
		if(a2!=a1)f=1;
	}
	if(f==0){
		cout<<"0";
		return 0;
		
	}
	int a4=0;
	for(int i=1;i<=n;i++){
		if(a[i]>m/2)a4=1;
	}

    if(l%2==0||a4==1){
    	cout<<m-k;
	}else cout<<m-k-1;
	return 0;
	
}
