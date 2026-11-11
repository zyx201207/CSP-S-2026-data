#include<iostream>
#include<string>
using namespace std;
struct str{
	long long len;
	char c;
}ch[200005];
int n;
long long ttlen,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ch[i].len>>ch[i].c;
		ttlen+=ch[i].len;
	}
	long long mid=0;
	if(ttlen&1){
		mid=ttlen/2+1;
		ttlen=0;
		long long sum=0,i=1;
		while(sum<mid){
			sum+=ch[i].len;
			i++;
		}
		long long midi=i;
		for(i=1;i<midi;i++){
			int d=min(ch[i].len,ch[n-i+1].len);
			if(ch[i].c!=ch[n-i+1].c){
				cnt+=d;
			}
			ch[i].len-=d,ch[n-i+1].len-=d;
			ttlen+=ch[i].len+ch[n-i+1].len;
		}
		ttlen+=ch[midi].len;
		if(ttlen&1){
			string s;
			for(i=1;i<=n;i++){
				if(ch[i].len==0){
					continue;
				}
				for(int j=1;j<=ch[i].len;j++);
				s+=ch[i].c;
			}
			mid=ttlen/2;
			for(i=0;i<mid;i++){
				cnt+=(s[i]!=s[s.size()+i-1]);
			}
		}
	}else{
		
	}
	cout<<cnt;
	return 0;
}
