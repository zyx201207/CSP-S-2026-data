//GZ-J00271，秦卓屹，贵阳市第一中学
#include<bits/stdc++.h> 
using namespace std;
long long n,num[200005],l,h,ans=0,t;
char str[200005];
string s;
int jdz(int a){
	if(a>=0)
		return a;
	else
		return -a;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	
	cin>>n;
	if(n<=2000){
		for(int i=0;i<n;i++){
			cin>>num[i]>>str[i];
			for(int j=0;j<num[i];j++)
			s+=str[i];
			l+=num[i];
		}
		h=(l+1)/2;
	for(int i=0;i<h;i++){
			if(s[i]-s[l-1-i])
				ans++;
		}
		cout<<ans;
	}
	else{
		for(int i=0;i<n;i++){
				cin>>num[i]>>str[i];
				l+=num[i];
		}
		int p=0;
		while(t<=(l+1)/2)
			t+=num[p++];
		int n1=t,n2=num[p]-t,w1=(l+1)/2,w2=(l+1)/2,p1=p,p2=p;
		for(int i=0;i<p;i++)
			n1-=num[i];
		while(w1!=0&&w2!=l){
			if(n1<n2){
				n1=num[p1--];
				n2-=n1;
				w1-=n1;
				w2+=n2;
			}
			else if(n1>n2){
				n2=num[p2++];
				n1-=n2;
				w1-=n1;
				w2+=n2;
			}
			else{
				n1=num[p1--];
				n2=num[p2++];
				w1-=n1;
				w2+=n2;
				if(str[p1]!=str[p2])
					ans+=n1;
			}
			if(str[p1]!=str[p2])
				ans+=jdz(n1-n2);
		}
		cout<<ans;
	}
	
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
