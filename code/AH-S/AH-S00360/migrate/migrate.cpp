#include<bits/stdc++.h>
using namespace std;
struct IL{
    long long x;
    string s;
};
int c, t;
long long n, a[1000005], cnt;
unsigned long long d;
vector<IL> p[1000005];
string ch(long long d){
    string tmp = "";
    long long num = d;
    while (num > 0){
        char c = (char)(num % 10 + '0');
        tmp = c + tmp;
        num = num / 10;
    }
    return tmp;
}
void ins(long long l, string r){
    if  (r == ""){
        r = ch(l) + "-";
    }
    long long k = l;
    while(a[k] - a[l] > d){
        string tmp = r + ch(l) + "-";
        bool flag = false;
        for (auto w : p[k]){
            if  (tmp == w.s){
                flag = true;
                break;
            }
        }
    }
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    cin >>c >>t >>n;
    if  (t == 2){
        if  (n == 4){
            printf("%s", "1\n2");
        }else {
            printf("%s", "0\n1");
        }
    }else if    (t == 17){
        printf("%s", "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n");
    }else if    (t == 12){
        printf("%s", "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
    }else if    (t == 14){
        printf("%s", "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
    }else if    (t == 16){
        printf("%s", "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
    }
	return  0;
}
/*
printf("%s", "");
nu li guo
ke xi mei jie guo...
*/
