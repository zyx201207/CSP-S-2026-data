#include <bits/stdc++.h>
using namespace std;
void judge(char,char);
int main() {
//	int k;
//	cin>>k;
//	while(k--) {
//	cout<<endl;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2;
	string x1,x2;
	cin>>s1>>x1>>s2>>x2;
	int c1=(x1[0]-'0')*10+(x1[1]-'0');//ÅÅºÅ
	int c2=(x2[0]-'0')*10+(x2[1]-'0');
	char ch1=x1[2];//×ùÎ»ºÅ£¬×ÖÄ¸
	char ch2=x2[2];
//	cout<<s1<<" "<<x1<<" "<<s2<<" "<<x2<<" "<<endl;
//	cout<<c1<<" "<<ch1<<" "<<c2<<" "<<ch2<<" "<<endl;

	if(s1==s2)cout<<"1";
	else {
		cout<<"0000";
//			continue;
		return 0;
	}
	if(c1==c2)cout<<"1";
	else {
		cout<<"000";
//			continue;
		return 0;
	}
	judge(ch1,ch2);
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void judge(char ch1,char ch2) {
	if(ch1>ch2)swap(ch1,ch2);
	int c1=ch1,c2=ch2;
	if(ch1=='D'&&ch2=='F') {
		cout<<"11";
		return;
	}
	if (abs(c2-c1)==1) {
		if(ch1=='C') {
			cout<<"00";
			return;
		}
		cout<<"11";
		return;
	} else {
		if(ch1=='A'&&ch2=='C') {
			cout<<"10";
			return;
		} else cout<<"00";
		return;
	}
	return ;
}
