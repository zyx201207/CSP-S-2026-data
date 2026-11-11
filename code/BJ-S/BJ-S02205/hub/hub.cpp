// Code by Happy-David_3367 on 2026 CSP-S2 competition.
// Problem: 
// .cpp ?
#include <bits/stdc++.h>
using namespace std;
#define MULTI_TEST

inline void solve() {printf ("0\n");
}
inline void main0(long start_clock = 0) {
	int T = 1;
	#ifdef MULTI_TEST
		scanf ("%d", &T);
	#endif
	while (T--) {
		// Remember to restore vars!!!
		solve ();
	}
	#ifdef Happy_David_3367_FLAG
		printf ("[Happy_David_3367_FLAG] Running Time Used: %.6Lf sec.\n", (clock () - start_clock) * (long double) 1 / CLOCKS_PER_SEC);
	#endif
}
int main() {
	const string prob_name = "";
	#ifndef Happy_David_3367_FLAG
		freopen ((prob_name + ".in").c_str (), "r", stdin);
		freopen ((prob_name + ".out").c_str (), "w", stdout);
		main0 ();
	#else
		const int samples_cnt = ;
		const string program_prefix = "";
		for (int sample = 1; sample <= samples_cnt; ++sample) {
			freopen ((prob_name + to_string (sample) + ".in").c_str (), "r", stdin);
			freopen ((program_prefix + '.' + prob_name + to_string (sample) + ".out").c_str (), "w", stdout);
			freopen ((program_prefix + '.' + prob_name + to_string (sample) + ".err").c_str (), "w", stderr);
			main0 (clock ());
			fclose (stdin);
			fclose (stdout);
			fclose (stderr);
		}
	#endif
	return 0;
}
// Head Snippet
/*
I can't understand the problem statement

CSP-J Extract Password: Trick||Treat!
CSP-S Extract Password: Oct31==Dec25?

通知 - 第二题样例说明
第二题（subway）中的样例解释请忽略公式中的变量部分，以文字叙述部分与公式中的数值部分为准。
This message was sent at 18:09, but just an hour ago, I was really confused by sample2...

Similar to CSP-J snippets
snippet.code-snippets
{
	// Place your BJ-S02205 workspace snippets here. Each snippet is defined under a snippet name and has a scope, prefix, body and 
	// description. Add comma separated ids of the languages where the snippet is applicable in the scope field. If scope 
	// is left empty or omitted, the snippet gets applied to all languages. The prefix is what is 
	// used to trigger the snippet and the body will be expanded and inserted. Possible variables are: 
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. 
	// Placeholders with the same ids are connected.
	// Example:
	// "Print to console": {
	// 	"scope": "javascript,typescript",
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
	"Head Snippet": {
		"prefix": "head",
		"body": "// Code by Happy-David_3367 on 2026 CSP-S2 competition.\n// Problem: $1\n// $2.cpp ?\n#include <bits/stdc++.h>\nusing namespace std;\n// #define MULTI_TEST$3\n$0\ninline void solve() {\n}\ninline void main0(long start_clock = 0) {\n\tint T = 1;\n\t#ifdef MULTI_TEST\n\t\tscanf (\"%d\", &T);\n\t#endif\n\twhile (T--) {\n\t\t// Remember to restore vars!!!\n\t\tsolve ();\n\t}\n\t#ifdef Happy_David_3367_FLAG\n\t\tprintf (\"[Happy_David_3367_FLAG] Running Time Used: %.6Lf sec.\\n\", (clock () - start_clock) * (long double) 1 / CLOCKS_PER_SEC);\n\t#endif\n}\nint main() {\n\tconst string prob_name = \"$4\";\n\t#ifndef Happy_David_3367_FLAG\n\t\tfreopen ((prob_name + \".in\").c_str (), \"r\", stdin);\n\t\tfreopen ((prob_name + \".out\").c_str (), \"w\", stdout);\n\t\tmain0 ();\n\t#else\n\t\tconst int samples_cnt = $5;\n\t\tconst string program_prefix = \"$6\";\n\t\tfor (int sample = 1; sample <= samples_cnt; ++sample) {\n\t\t\tfreopen ((prob_name + to_string (sample) + \".in\").c_str (), \"r\", stdin);\n\t\t\tfreopen ((program_prefix + '.' + prob_name + to_string (sample) + \".out\").c_str (), \"w\", stdout);\n\t\t\tfreopen ((program_prefix + '.' + prob_name + to_string (sample) + \".err\").c_str (), \"w\", stderr);\n\t\t\tmain0 (clock ());\n\t\t\tfclose (stdin);\n\t\t\tfclose (stdout);\n\t\t\tfclose (stderr);\n\t\t}\n\t#endif\n\treturn 0;\n}\n// Head Snippet",
		"description": "Head Snippet"
	},
	"Debug Snippet": {
		"prefix": ["debug", "dbg"],
		"body": "#ifdef Happy_David_3367_FLAG\n\tfprintf (stderr, \"[Happy_David_3367_FLAG] [Flag $1] $2.\\n\", $3);\n#endif // Debug Snippet",
		"description": "Debug Snippet"
	}
}

VSCode is really great

BJ-J02217
BJ-S02205
2012-03-22
You can find me anywhere using the username HappyDavid or HappyDavid3367 or Happy-David_3367, but please don't message me
*/