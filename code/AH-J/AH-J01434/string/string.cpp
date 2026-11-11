#include <bits/stdc++.h>
using namespace std;
long long n,x,l[200005];
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x;
		cin>>ch[i];
		l[i]=l[i-1]+x;
	}
	for (int i=1;i<=n;i++){
		if(l[i]*2>l[n]){
			x=i;
			break;
		}
	}
	long long p=0;
	long long nowl=l[1],nowr=l[n]-l[n-1];
	int nows1=1,nows2=n;
	while(nows1<x&&nows2>x){
		if(ch[nows1]==ch[nows2]){
			if (nowl>=nowr){
				nowl-=nowr;
				nows2--;
				nowr=l[nows2]-l[nows2-1];
			}else{
				nowr-=nowl;
                                nows1++;
                                nowl=l[nows1]-l[nows1-1];
			}
		}else{
        		if (nowl>=nowr){
                                nowl-=nowr;
				p+=nowr;
                                nows2--;
                                nowr=l[nows2]-l[nows2-1];
                        }else{
      				nowr-=nowl;
				p+=nowl;
                                nows1++;
                                nowl=l[nows1]-l[nows1-1];
                        }
		}
	}
        if(nows1==x){
		if(ch[nows2]!=ch[x]) p+=nowr;
		for (int i=x+1;i<=nows2-1;i++){
			if (ch[x]!=ch[i]) p+=l[i]-l[i-1];
		}
	}else{
		if(ch[nows1]!=ch[x]) p+=nowl;
		for (int i=nows1+1;i<=x-1;i++){
			if (ch[x]!=ch[i]) p+=l[i]-l[i-1];
		}
	}
        cout<<p;
	return 0;
}
