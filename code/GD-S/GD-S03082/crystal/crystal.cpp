#include<bits/stdc++.h>
using namespace std;
int adress[500005][20],maxx=0; 
string k;
int cnt[1000005],tot=0,x,n,m;
void cr(string s){
	int p=0;
	bool flag=false;
	if(s[0]=='-') flag=true;
	if(flag){
		for(int i=1;i<s.size();i++){
			if(adress[p][s[i]-'0'+10]==0){	
				adress[p][s[i]-'0'+10]=++tot;
				p++;
				if(i==s.size()-1){
					cnt[tot]++;
					if(cnt[maxx]<cnt[p]){
						maxx=p;
						x=tot;
					} 
				}
			}else{
				p=adress[p][s[i]-'0'+10];
				if(i==s.size()-1){
					cnt[p]++;
					if(cnt[maxx]<cnt[p]){
						maxx=p;
						x=p;
					} 
				}
			}	
		}
	}else{
		for(int i=0;i<s.size();i++){
			if(adress[p][s[i]-'0']==0){	
				adress[p][s[i]-'0']=++tot;
				p++;
				if(i==s.size()-1){
					cnt[tot]++;
					if(cnt[maxx]<cnt[p]){
						maxx=p;
						x=tot;
					} 
				}
			}else{
				p=adress[p][s[i]-'0'];
				if(i==s.size()-1){
					cnt[p]++;
					if(cnt[maxx]<cnt[p]){
						maxx=p;
						x=p;
					} 
				}
			}
		}
	}
	return;
}
void ans(){
	
	int anss=cnt[maxx];
	cout<<x<<" "<<anss<<endl;
	if(10<x&&x<=20){
		for(int i=x;i>=10;i--){
			for(int j=0;j<cnt[i];j++){
				if(m>=j){
					m-=j;
					anss++;
				}else{
					cout<<anss;
					return;
				}
			}
		}		
	}else{
		cout<<"x:"<<x<<endl;
		for(int i=x-1;i>=0;i--){
			cout<<"x-1:"<<i<<endl;
			for(int j=0;j<cnt[i];j++){
				cout<<"cnt[i]:"<<cnt[i]<<endl<<"  maxx-cnt[i]:"<<maxx-cnt[i];
				cout<<"maxx："<<maxx<<endl; 
				if(m>=maxx-cnt[i]){
					m-=maxx-cnt[i];
					anss+=1;
					cout<<"中了哈哈哈"<<anss<<endl; 
				}else{
					cout<<"呜呜呜"<<endl; 
					cout<<anss;
					return;
				}
			}
		}
	}
	return ;
}
int main(){
	//Oct31==Dec25?
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k;
		cr(k); 
	}
	ans();
	//sort(a,a+n);//从小到大 
	return 0;
} 
