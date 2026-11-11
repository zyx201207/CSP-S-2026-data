#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#define ll long long
using namespace std;
struct str{
	int num,c;
};
str s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	bool flag=0;
	char a;
	for(ll i=1;i<=n;i++){
		ll temp;
		cin>>temp;
		char cc;
		cin>>cc;
		if(i==1){
			a=cc;
		}
		else{
			if(a!=cc){
				flag=1;
			}
		}
		s[i].num=temp;
		s[i].c=cc;
	}
	if(flag==0){
		cout<<"0";
		return 0;
	}
	ll sum=0;
	ll i=1,j=n;
	while(i<j){
		if(s[i].c==s[j].c){//字母相同 
			if(s[i].num==s[j].num){//数量相同 
				i++;
				j--;
			}
			else{//数量不同 
				if(s[i].num<s[j].num){//i组少 		
					s[j].num-=s[i].num;
					i++;
				}
				else{//j组少 
					s[i].num-=s[j].num; 
					j--;
				}
			}
		}
		else{//字母不同 
			if(s[i].num==s[j].num){//数量相同 
				sum+=s[i].num;
				i++;
				j--;	
			}
			else{//数量不同 
				if(s[i].num<s[j].num){//i组少 
					s[j].num-=s[i].num;
					sum+=s[i].num; 
					i++; 
				}
				else{//j组少 
					s[i].num-=s[j].num;
					sum+=s[j].num; 
					j--;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
