#include<bits/stdc++.h>
using namespace std;
long long n,b[200001]={0},w1=0,w2=0,k1=1,k2=1;
long long cnt=0,ans=0;
string s="",ss="";
void f(){
	for(int i=1;i<=(cnt+1)/2;i++){
		if(i>w1){
			if(w1+b[k1]>(cnt+1)/2){
				w1=(w1+b[k1])-(w1+b[k1])%((cnt+1)/2);
			}
			else {
				w1=(w1+b[k1]);
			}
			k1++;
		}
		if(cnt-i<w2){
			if(w2-b[k2]<(cnt+1)/2){
				w2=(w2-b[k2])+((cnt+2)/2)%(w2-b[k2]);
			}
			else {
				w2=(w2-b[k2]);
			}
			k2--;
		}
		if(s[k1]!=s[k2+1]){
			ans++;
		}
		//cout<<i<<" "<<w1<<" "<<k1<<" "<<cnt-i<<" "<<w2 <<" "<<k2<<endl;
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>s[i];
		cnt+=b[i];	
	}
	//for(int i=1;i<=n;i++)cout<<i<<" "<<b[i]<<" "<<s[i]<<endl;
	k2=n+1 ;w2=cnt;w1=b[1];
	f();
	fclose(stdin);
	fclose(stdout);
}

