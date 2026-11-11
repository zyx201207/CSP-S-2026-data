#include<bits/stdc++.h> 
using namespace std;
struct part{
	long long begin,end,length;
	char value;
}s[233333];
int n;
long long tlen;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		s[i].begin=s[i-1].end+1;
		s[i].end=s[i].begin+x-1;
		s[i].value=y;
		s[i].length=x;
	}
	tlen=s[n].end;
	long long ans=0;
	for(int i=1,j=n;i<=j;){
		if(s[i].value==s[j].value){
			if(s[i].length>s[j].length){
				s[i].length-=s[j].length;
				s[i].begin+=s[j].length;
				j--;
			}else if(s[i].length<s[j].length){
				s[j].length-=s[i].length;
				s[j].end-=s[j].length;
				i++;
			}else{
				i++; 
				j--;
			}
		}else{
			if(s[i].length>s[j].length){
				ans+=s[j].length;
				s[i].length-=s[j].length;
				s[i].begin+=s[j].length;
				j--;
			}else if(s[i].length<s[j].length){
				ans+=s[i].length;
				s[j].length-=s[i].length;
				s[j].end-=s[j].length;
				i++;
			}else{
				ans+=s[i].length;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
