#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,d;
	string t1,t2;
	cin>>a>>t1>>b>>t2;
	c=t1[0]-'0';
	d=t2[0]-'0';
	c*=10;
	d*=10;
	c+=t1[1]-'0';
	d+=t2[1]-'0';
	char s1=t1[2];
	char s2=t2[2];
	//第一个问题    两张车票对应的座位是否在同一节车厢；
	if(a==b) {
		cout<<"1";
		//第二个问题	两张车票对应的座位是否在同一节车厢的同一排；
		if(c==d) {
			cout<<"1";
			//第三个问题	两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
			if(('A'<=s1&&s1<='C'&&'A'<=s2&&s2<='C')||('D'<=s1&&s1<='E'&&'D'<=s2&&s2<='E')){
				cout<<"1";
				//第四个问题 	两张车票对应的座位是否相邻。
				if(s1+1==s2||s1-1==s2){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}




	return 0;
}
