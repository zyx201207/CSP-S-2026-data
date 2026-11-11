#include<bits/stdc++.h>
using namespace std;
string c=" ";//最终待处理字符串 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long l=0;//本段字符串长度 
		char a;//本段字符串 
		cin>>l>>a; 
		int k=0;
		while(l--){
			c+=a;
		}
	}
	int mincnt=99999;
	if((c.size()-1)%2){//#1情况c.size为奇数  
		int h=(c.size()-1)/2+1;
		int cnt=0;
		for(int i=1;i<h;i++){
			if(c[i]!=c[c.size()-i]) cnt++;
		}
		if(cnt<mincnt) mincnt=cnt;
	}
	if((c.size()-1)%2==0) {//#2情况c.size为奇数  
		int h=(c.size()-1)/2;
		int cnt=0;
		for(int i=1;i<=h;i++){
			if(c[i]==c[c.size()-i]) cnt++;
		}
		if(cnt<mincnt) mincnt=cnt;
	} 
//	if((c.size()-1)%2){//#1情况c.size为奇数 按后半部分进行回文 
//		int h=(c.size()-1)/2+1;
//		int cnt=0;
//		for(int i=h+1;i<c.size;i++){
//			if(c[i]!=c[c.size()-i]) cnt++;
//		}
//		min(mincnt,cnt);
//	}
	cout<<mincnt;
	return 0;
}
