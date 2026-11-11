#include<bits/stdc++.h>
#define int long long
using namespace std;

//TYX
struct note{
	int many;
	char id;
};
note a[200010];
/*
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	dashang QAQ
	
	*/
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int ans;
		char c;
		cin>>ans>>c;
		cnt+=ans;
		a[i]={ans,c};
	}
	stack<note>st;
	stack<note>st1;
	int f=0;
	if(cnt%2){
		f=1;
		cnt++;
	}
	cnt/=2;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(sum>=cnt)break;
		if((sum+a[i].many)<=cnt){
			sum+=a[i].many;
			st.push(a[i]);
		}
		else{
			st.push({cnt-sum,a[i].id});
			break;
		}
	}
	sum=0;
	for(int i=n;i>=1;i--){
		if(sum>=cnt)break;
		if((sum+a[i].many)<=cnt){
			sum+=a[i].many;
			st1.push(a[i]);
		}
		else{
			st1.push({cnt-sum,a[i].id});
			break;
		}	
	}
	int fin=0;
	while(st.size()){
		note l1=st.top(),l2=st1.top();
		st.pop();
		st1.pop();
		if(l1.id==l2.id){
			if(l1.many>l2.many){
				l1.many-=l2.many;
				st.push(l1);
			}
			else if(l1.many==l2.many){
				continue;
			}else{
				l2.many-=l1.many;
				st1.push(l2);
			}
		}else{
			if(l1.many>l2.many){
				l1.many-=l2.many;
				fin+=l2.many;
				st.push(l1);
			}
			else if(l1.many==l2.many){
				fin+=l1.many;
				continue;
			}else{
				fin+=l1.many;
				l2.many-=l1.many;
				st1.push(l2);
			}
		}
	}cout<<fin;
    return 0;
}
