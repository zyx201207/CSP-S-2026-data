#include <bits/stdc++.h>
using namespace std;
int a,b,e,d;
char c,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d >> e >> f;
    if(a==d){
        cout << 1;
        if(b==e){
            cout << 1;
            if((67.5-int(c))*(67.5-int(f))>0){
                cout << 1;
                if(abs(c-f)==1||(c=='F'&&f=='D')||(c=='D'&&f=='F'))cout << 1;
                else cout << 0;
            }else cout << "00";
        }else cout << "000";
    }else cout << "0000";
    return 0;
}

/*
闲来无事，随便统计一下。
代码长度（不计算本条注释）：555B
字符统计（不计算本条注释）：
\n:21
(空格):171
":14
#:1
&:4
':8
(:14
):14
*:1
+:2
,:8
-:3
.:5
/:1
0:12
1:5
5:2
6:2
7:2
;:15
<:17
=:14
>:14
D:2
F:2
a:10
b:5
c:19
d:8
e:21
f:12
g:1
h:2
i:15
l:7
m:2
n:14
o:12
p:3
r:8
s:12
t:22
u:13
v:2
w:1
{:4
|:4
}:4
*/
