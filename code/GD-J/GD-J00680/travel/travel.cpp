#\
i\
n\
c\
l\
u\
d\
e\
 \
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
using namespace std;

int c1,c2,l1,l2;
string s1,s2;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel5.in","r",stdin);
//	freopen("travel5.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	l1=(s1[0]-'0')*10+s1[1]-'0';
	l2=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2){
		cout<<1;
		if(l1==l2){
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	akioi;
}
//02 01A 02 01B
